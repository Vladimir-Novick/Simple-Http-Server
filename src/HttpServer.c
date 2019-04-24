/*
 ============================================================================
 Name        : HttpServer.c
 Author      : Vladimir Novick
 Version     :
 Copyright   : Vladimir Novick, vlad.novick@gmail.com
 Description :  C, Ansi-style
 ============================================================================
 */
#include "HttpRoute.h"




int main(int c, char **v) {
  serve_forever("8081");
  return 0;
}

void route(header_t *reqhdr, char * uri, char *method, int payload_size) {
  ROUTE_START()

  ROUTE_GET("/") {
    printf("HTTP/1.1 200 OK\r\n\r\n");
    printf("Simple HTTP Server :\r\n\r\n");
    printf("You are using %s", request_header("User-Agent", reqhdr));
  }

  ROUTE_GET("/test") {
    printf("HTTP/1.1 200 OK\r\n\r\n");
    printf("Simple HTTP Server :\r\n\r\n");
    printf("List of request headers:\r\n\r\n");

    header_t *h = request_headers(reqhdr);

    while (h->name) {
      printf("%s: %s\n", h->name, h->value);
      h++;
    }
  }

  ROUTE_POST("/") {
    printf("HTTP/1.1 200 OK\r\n\r\n");
    printf("Simple HTTP Server :\r\n\r\n");
    printf("Fetch the data using `payload` variable.");
    printf("POSTed %d bytes. \r\n", payload_size);
  }

  ROUTE_END()
}
