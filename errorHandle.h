#ifndef ERROR_HANDLE_H
#define ERROR_HANDLE_H

#define ERR(x) printf("fatal error | line %d | file %s\n%s\n", __LINE__, __FILE__, x)
#define WARN(x) printf("WARNING | line %d | file %s\n%s\n", __LINE__, __FILE__, x)

#endif