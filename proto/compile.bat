@protoc --cpp_out=../src/dependencies/proto ./Request.proto
@protoc --cpp_out=../src/dependencies/proto ./Response.proto
@protoc --python_out=../src/dependencies/proto/test ./Request.proto
@protoc --python_out=../src/dependencies/proto/test ./Response.proto
@pause