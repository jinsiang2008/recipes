#!/usr/bin/env python
""" ssh_exec.py: ssh to vm and execute commands. """

import paramiko
import argparse
import os

PRIVATE_KEY_PATH = os.path.expanduser("~/.ssh/id_rsa")
HOSTNAME = "<IP>"
USERNAME = "<USERNAME>"

def SSH_connect(hostname, username, private_key_path):
    """ Setup SSH connection to appliance
    """
    k = paramiko.RSAKey.from_private_key_file(private_key_path)
    c = paramiko.SSHClient()
    c.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    c.connect( hostname = hostname, username = username, pkey = k )
    return c

def execute(client, cmds):
    cmd_line = '\n'.join(cmds)
    stdin , stdout, stderr = client.exec_command(cmd_line)
    print stdout.read()
    if len(stderr.read()):
        print "Error:", stderr.read()
    client.close()

if __name__ == '__main__':
    client = SSH_connect(HOSTNAME, USERNAME, PRIVATE_KEY_PATH)
    cmds = ["ls -l", "ls -1"]
    execute(client, cmds)

