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

Verification command:
```bash
sudo crontab -l
```

## SSH

SSH is enabled on port **4242**.
Root login via SSH is disabled for security reasons.

SSH is also used to interact with the virtual machine from the host system.

Verification command:
```bash
sudo systemctl status ssh
ssh leilai@localhost -p 4242
```


