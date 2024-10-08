#define _XOPEN_SOURCE 500

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ENCODED_PATH_MAX PATH_MAX
const char hexnums[] = {'0', '1', '2', '3',
			'4', '5', '6', '7',
			'8', '9', 'A', 'B',
			'C', 'D', 'E', 'F'};

int main() {
  char path_buffer[PATH_MAX];
  char encoded_buffer[ENCODED_PATH_MAX];
  if (getcwd(path_buffer, PATH_MAX) == NULL) {
    perror("Error");
    return 1;
  }
  size_t out_len = 0;
  const size_t path_buffer_len = strlen(path_buffer);
  for (size_t i = 0; i < path_buffer_len; i++) {
    char c = path_buffer[i];
    if (isalnum(c) || strchr("-/:_.!'()~", c)) {
      if (out_len + 1 >= ENCODED_PATH_MAX) {
	goto failed_encoding;
      }
      encoded_buffer[out_len] = c;
      ++out_len;
    } else {
      if (out_len + 3 >= ENCODED_PATH_MAX) {
	goto failed_encoding;
      }
      encoded_buffer[out_len] = '%';
      encoded_buffer[out_len + 1] = hexnums[((unsigned char) c) >> 4];
      encoded_buffer[out_len + 2] = hexnums[c & 0x0f];
      out_len += 3;
    }
  }
  if (out_len >= ENCODED_PATH_MAX) {
  failed_encoding:
    encoded_buffer[0] = '/';
    out_len = 1;
  }
  encoded_buffer[out_len] = '\0';

  char hostname_buffer[HOST_NAME_MAX];
  gethostname(hostname_buffer, HOST_NAME_MAX);
  hostname_buffer[HOST_NAME_MAX - 1] = '\0';

  printf("\e]7;file://%s%s\e\\", hostname_buffer, encoded_buffer);
#ifdef DEBUG
  printf("file://%s%s\n", hostname_buffer, encoded_buffer);
#endif
  return 0;
}
