// Copyright (c) 2016 Annotator Team
#include "api/ApiHandler.h"
#include "api/UriParser.h"
#include "api/AnnotationsHandler.h"

#include <Poco/File.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/RegularExpression.h>
#include <Poco/URI.h>
#include <Poco/Util/Application.h>

#include "AccessDeniedHandler.h"
#include "FileHandler.h"
#include "NotFoundHandler.h"

ApiHandler::ApiHandler() {}

void ApiHandler::handleRequest(Poco::Net::HTTPServerRequest& request,
                               Poco::Net::HTTPServerResponse& response) {
  UriParser uri(request.getURI());

  if (uri.isAnnotations() || uri.isAnnotation()) {
      AnnotationsHandler annotationsHandler;
      annotationsHandler.handleRequest(request, response);

  } else {
    NotFoundHandler notFoundHandler;
    notFoundHandler.handleRequest(request, response);
  }
}
