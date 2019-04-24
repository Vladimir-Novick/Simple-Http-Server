#ifndef _HTTPD_H___
#define _HTTPD_H___

#include <string.h>
#include <stdio.h>

#define MAX_CONNECTIONS 1000

void startServer(const char *);
void respond(int);

void serve_forever(const char *PORT);

typedef struct { char *name, *value; } header_t;

// user shall implement this function

void route(header_t *reqhdr, char * uri, char *method,int payload_size);

header_t *request_headers( header_t *reqhdr);

char *request_header( const char *name , header_t *_reqhdr);


#define ROUTE_START() if (0) {
#define ROUTE(METHOD, URI)                                                     \
  }                                                                            \
  else if (strcmp(URI, uri) == 0 && strcmp(METHOD, method) == 0) {
#define ROUTE_GET(URI) ROUTE("GET", URI)
#define ROUTE_POST(URI) ROUTE("POST", URI)
#define ROUTE_END()                                                            \
  }                                                                            \
  else printf("HTTP/1.1 500 Internal Server Error\n\n"                         \
              "The server has no handler to the request.\n");


#endif
