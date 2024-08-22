#!/bin/bash

printf "Content-type: text/plain\n\n"
echo "-------------------------"
echo "CGI Environment Variables:"
echo "-------------------------"
echo "HTTP_USER_AGENT: $HTTP_USER_AGENT"
echo "REMOTE_ADDR: $REMOTE_ADDR"
echo "SERVER_NAME: $SERVER_NAME"
echo "SERVER_PORT: $SERVER_PORT"
echo "QUERY_STRING: $QUERY_STRING"
echo "REQUEST_METHOD: $REQUEST_METHOD"
echo "SCRIPT_NAME: $SCRIPT_NAME"
echo "SCRIPT_FILENAME: $SCRIPT_FILENAME"
echo "SERVER_PROTOCOL: $SERVER_PROTOCOL"