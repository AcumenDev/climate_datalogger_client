#include <iostream>

#include "pb.h"
#include "pb_common.h"
#include "pb_decode.h"
#include "pb_encode.h"
#include "TemperatureProtocol.pb.h"


bool encode(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {
    uint16_t value = *(uint16_t *) arg;
    // pb_encode_string(stream,)
    return true;
}

bool encode_string_key(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {
    printf("encode_string...\n");

    const  char *str = "53ae8ff6-3d8c-11e8-b467-0ed5f89f718b";

    if (!pb_encode_tag_for_field(stream, field))
        return false;

    return pb_encode_string(stream, (uint8_t *) str, strlen(str));
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    uint8_t buffer[128];
    size_t message_length;
    bool status;


    AuthRequest authRequest = AuthRequest_init_default;


    authRequest.type = 1;
    authRequest.version = 1;

    char key[] = "53ae8ff6-3d8c-11e8-b467-0ed5f89f718b";


    authRequest.apiKey.funcs.encode = encode_string_key;
//    authRequest.apiKey.arg = key;


    pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

    status = pb_encode(&stream, AuthRequest_fields, &authRequest);
    message_length = stream.bytes_written;


    std::cout << "message_length " << message_length << std::endl;
    std::cout << "message " << std::endl;
    for (uint32_t i = 0; i < message_length; i++) {
        std::cout << std::hex << (unsigned int) (buffer[i]) << " ";
    }
    std::cout << std::endl;



    /* Then just check for any errors.. */
    if (!status) {
        printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
        return 1;
    }


    return 0;
}