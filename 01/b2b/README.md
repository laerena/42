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

---

### Debian vs Rocky Linux
| Debian | Rocky Linux |
|--------|-------------|
| Beginner-friendly | More complex |
| Uses AppArmor | Uses SELinux |
| Uses UFW | Uses firewalld |
| Faster setup | Enterprise-oriented |

Debian was selected for clarity and ease of maintenance.

---

### AppArmor vs SELinux
- **AppArmor (Debian)**: profile-based, easier to configure
- **SELinux (Rocky)**: policy-based, more granular but complex

AppArmor was chosen due to simpler configuration and readability.

---

### UFW vs firewalld
- **UFW**: simple, rule-based, easy to audit
- **firewalld**: zone-based, more complex
UFW was selected to reduce configuration complexity.

---

### VirtualBox vs UTM
- **VirtualBox**: cross-platform, widely used at 42
- **UTM**: required for Apple Silicon

VirtualBox was used in this project.

---

### Disk & Partitioning
- Encrypted partitions using **LVM**
- No graphical interface installed
- Minimal services to reduce attack surface

---

## Security Configuration

### Users & Groups
The system includes:
- Root user: 'leilai42'
- Personal user: 'leilai'
- Groups:
    - 'sudo'
    - 'user42'

```bash
getent group sudo
getent group user42
groups leilai
```

### Password Policy

### Crontab
- edit monitoring.sh
    - sudo nano /home/leilai/monitoring.sh
- edit file to introduce tasks to be run by cron
    - sudo crontab -l
    - sudo crontab -e

- copy content from vm through terminal: 
    - ssh leilai@localhost -p 4242
