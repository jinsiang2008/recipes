# From https://docs.docker.com/engine/examples/running_ssh_service/#run-a-test_sshd-container
FROM ubuntu:16.04

RUN apt-get update && apt-get install -y openssh-server
RUN mkdir /var/run/sshd
RUN echo 'root:passwd' | chpasswd
RUN sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config

# SSH login fix. Otherwise user is kicked off after login
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

ENV NOTVISIBLE "in users profile"
RUN echo "export VISIBLE=now" >> /etc/profile

# os will assign a mapped port for you when `docker run -P`
EXPOSE 22
# or, EXPOSE 22:8200
CMD ["/usr/sbin/sshd", "-D"]
