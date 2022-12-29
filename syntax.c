#include <string.h>
#include <syntax.h>

// C/C++

int st_c_depth(const char *line, int length);
char st_c_pair(const char *line, int length, char chr);
int st_c_color(int prev_state, int *state, const char *text, int length);

// Default

static int st_depth(const char *line, int length);
static char st_pair(const char *line, int length, char chr);
static int st_color(int prev_state, int *state, const char *text, int length);

// syntax.h stuff

syntax_t st_init(const char *filename) {
  filename = strrchr(filename, '.');
  
  if (filename) {
    if (strstr(".h.c.hpp.cpp", filename)) {
      return (syntax_t){
        .lang = "C/C++",
        .f_depth = st_c_depth,
        .f_pair = st_c_pair,
        .f_color = st_c_color,
      };
    }
  }
  
  return (syntax_t){
    .lang = "Text/Unknown",
    .f_depth = st_depth,
    .f_pair = st_pair,
    .f_color = st_color,
  };
}

static int st_depth(const char *line, int length) {
  line; length;
  return 0;
}

static char st_pair(const char *line, int length, char chr) {
  line; length; chr;
  return '\0';
}

static int st_color(int prev_state, int *state, const char *text, int length) {
  prev_state; text; length;
  *state = 0;
  
  return st_color_default;
}
