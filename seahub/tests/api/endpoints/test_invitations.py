import json
from mock import patch

from post_office.models import Email

from seahub.base.accounts import UserPermissions
from seahub.invitations.models import Invitation
from seahub.test_utils import BaseTestCase
from seahub.api2.permissions import CanInviteGuest

class InvitationsTest(BaseTestCase):
    def setUp(self):
        self.login_as(self.user)
        self.endpoint = '/api/v2.1/invitations/'
        self.username = self.user.username

    @patch.object(CanInviteGuest, 'has_permission')
    @patch.object(UserPermissions, 'can_invite_guest')
    def test_can_add(self, mock_can_invite_guest, mock_has_permission):

        mock_can_invite_guest.return_val = True
        mock_has_permission.return_val = True

        assert len(Invitation.objects.all()) == 0
        resp = self.client.post(self.endpoint, {
            'type': 'guest',
            'accepter': 'some_random_user@1.com',
        })
        self.assertEqual(201, resp.status_code)

        json_resp = json.loads(resp.content)
        assert json_resp['inviter'] == self.username
        assert json_resp['accepter'] == 'some_random_user@1.com'
        assert json_resp['expire_time'] is not None

        assert len(Invitation.objects.all()) == 1

    @patch.object(CanInviteGuest, 'has_permission')
    @patch.object(UserPermissions, 'can_invite_guest')
    def test_can_send_mail(self, mock_can_invite_guest, mock_has_permission):

        mock_can_invite_guest.return_val = True
        mock_has_permission.return_val = True

        self.assertEqual(len(Email.objects.all()), 0)

        resp = self.client.post(self.endpoint, {
            'type': 'guest',
            'accepter': 'some_random_user@1.com',
        })
        self.assertEqual(201, resp.status_code)
        json_resp = json.loads(resp.content)

        self.assertEqual(len(Email.objects.all()), 1)
        self.assertRegexpMatches(Email.objects.all()[0].html_message,
                                 json_resp['token'])

    @patch.object(CanInviteGuest, 'has_permission')
    @patch.object(UserPermissions, 'can_invite_guest')
    def test_can_list(self, mock_can_invite_guest, mock_has_permission):

        mock_can_invite_guest.return_val = True
        mock_has_permission.return_val = True

        Invitation.objects.add(inviter=self.username, accepter='1@1.com')
        Invitation.objects.add(inviter=self.username, accepter='1@2.com')

        resp = self.client.get(self.endpoint)
        self.assertEqual(200, resp.status_code)
        json_resp = json.loads(resp.content)
        assert len(json_resp) == 2
