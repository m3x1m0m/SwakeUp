IF NOT EXIST embc   mkdir embc
IF NOT EXIST cpp    mkdir cpp

"generator\protoc.exe" --nanopb_out=embc --cpp_out=cpp swakeup.proto