**This project has been created as part of the 42 curriculum by leilai.**

# Born2BeRoot

## Description

**Born2BeRoot** is a system administration project focused on virtualization and Linux server configuration.
The goal is to create and secure a virtual machine while following strict rules related to security, user management, networking, and system monitoring.

The project introduces:
- Virtual machines and operating systems
- Linux system administration basics
- Security policies (passwords, sudo, SSH, firewall)
- Disk partitioning with encrypted LVM
- Automation using Bash scripts and cron

---

## Project Overview & Design Choices

### Operating System Choice

**Debian** was chosen for this project.

**Pros**
- Stable and well-documented
- Large community support
- Simpler configuration for beginners

**Cons**
- Slightly older packages compared to rolling distributions

```bash
uname -a
lsb_release -a
hostnamectl
```


### Debian vs Rocky Linux
| Debian | Rocky Linux |
|--------|-------------|
| Beginner-friendly | More complex |
| Uses AppArmor | Uses SELinux |
| Uses UFW | Uses firewalld |
| Faster setup | Enterprise-oriented |

Debian was selected for clarity and ease of maintenance.


### AppArmor vs SELinux
- **AppArmor (Debian)**: profile-based, easier to configure
- **SELinux (Rocky)**: policy-based, more granular but complex

AppArmor was chosen due to simpler configuration and readability.


### UFW vs firewalld
- **UFW**: simple, rule-based, easy to audit
- **firewalld**: zone-based, more complex

UFW was selected to reduce configuration complexity.


### VirtualBox vs UTM
- **VirtualBox**: cross-platform, widely used at 42
- **UTM**: required for Apple Silicon

VirtualBox was used in this project.


### Disk & Partitioning
- Encrypted partitions using **LVM**
- No graphical interface installed
- Minimal services to reduce attack surface

```bash
lsblk
```

---

## Security Configuration

### Users & Groups
The system includes:
- Root user: `leilai42`
- Personal user: `leilai`
- Groups:
    - `sudo`
    - `user42`

```bash
getent group sudo
getent group user42
groups leilai
```


### Password Policy

A strong password policy was implemented using PAM and login definitions.

The following rules were applied:
- Password expires every 30 days
- Minimum of 2 days before a password can be changed
- Warning message displayed 7 days before expiration
- Minimum length of 10 characters
- Must contain at least one uppercase letter, one lowercase letter, and one number
- Must not contain the username
- No more than 3 consecutive identical characters
- Root password follows the same policy

Verification commands:
```bash
sudo chage -l leilai
sudo nano /etc/login.defs
sudo nano /etc/pam.d/common-password
```

After configuring the password policy, all existing passwords were updated
to ensure the rules were applied correctly.

Changing password commands:
```bash
passwd
sudo passwd leilai
sudo passwd root
```


### Sudo Configuration

The `sudo` utility was configured following strict security rules to limit misuse
and improve traceability.

Applied rules:
- Authentication is limited to **3 attempts**
- A **custom error message** is displayed on incorrect password entry
- All sudo commands are **logged**, including input and output
- **TTY mode** is enabled for security reasons
- The PATH used by sudo is **restricted**

Verification commands:
```bash
sudo visudo
sudo -V
ls /var/log/sudo/
```


### Firewall

The firewall was configured using **UFW (Uncomplicated Firewall)** to restrict
incoming connections.

Applied rules:
- Firewall enabled at system startup
- Only port **4242** is allowed
- All other incoming connections are blocked

Verification commands:
```bash
sudo ufw status
sudo ufw status verbose
```
Port access is managed using UFW rules.

Managing commands:
```bash
sudo ufw allow 4242
sudo delete allow 4242
sudo ufw enable
sudo ufw disable
sudo ufw status numbered
```


### SSH

SSH is enabled on port **4242**.
Root login via SSH is disabled for security reasons.

SSH is also used to interact with the virtual machine from the host system.

Verification command:
```bash
sudo systemctl status ssh
ssh leilai@localhost -p 4242
```

---

## Monitoring Script

A Bash script (`monitoring.sh`) was created to display system information automatically.

The script runs every 10 minutes using `cron` and broadcasts information to all terminals using `wall`.

Displayed information includes:
- System architecture and kernel version
- Physical and virtual CPU count
- RAM usage and percentage
- Disk usage and percentage
- CPU load
- Last reboot time
- LVM usage status
- Active TCP connections
- Logged-in users
- Network IP and MAC address
- Number of sudo commands executed

Verification & Modification commands:
```bash
sudo crontab -l
sudo crontab -e
sudo systemctl status cron
```

---

## Instructions

No compilation is required for this project.

The system configuration can be verified using the commands listed in each section
of this README. All configurations were applied directly on the virtual machine.

---

## Resources

- Debian Documentation  
  https://www.debian.org/doc/

- AppArmor Documentation  
  https://wiki.ubuntu.com/AppArmor

- UFW Documentation  
  https://help.ubuntu.com/community/UFW

- OpenSSH Documentation  
  https://www.openssh.com/manual.html

### AI Usage

AI tools were used as learning support to clarify Linux system administration
concepts and command usage.

No configuration files or scripts were copied.
All implementations were written and configured manually.
