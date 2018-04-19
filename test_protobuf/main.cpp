#include <iostream>

#include "pb/pb.h"
#include "pb/pb_common.h"
#include "pb/pb_decode.h"
#include "pb/pb_encode.h"
#include "pb/BaseMessage.pb.h"
#include "pb/Temperature.pb.h"

void printBytes(const uint8_t *bufferAuth, size_t sizeAuth) {
    std::cout << "message_length " << sizeAuth << std::endl;
    std::cout << "message " << std::endl;
    for (uint32_t i = 0; i < sizeAuth; i++) {
        std::cout << std::hex << (unsigned int) (bufferAuth[i]) << " ";
    }
    std::cout << std::endl;
}


bool encode_string_key(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {


    const char *str = "53ae8ff6-3d8c-11e8-b467-0ed5f89f718b";

    if (!pb_encode_tag_for_field(stream, field)) {
        return false;
    }
    printf("encode_string...\n");
    return pb_encode_string(stream, (uint8_t *) str, strlen(str));
}


bool encode_baseMessage(pb_ostream_t *stream, const pb_field_t messagetype[], const void *message) {
    const pb_field_t *field;
    for (field = BaseMessage_fields; field->tag != 0; field++) {
        if (field->ptr == messagetype) {
            /* This is our field, encode the message using it. */
            if (!pb_encode_tag_for_field(stream, field)) {
                return false;
            }

            return pb_encode_submessage(stream, messagetype, message);
        }
    }

    /* Didn't find the field for messagetype */
    return false;
}

size_t auth(uint8_t *buffer, size_t bufsize) {
    bool status;


    Auth authRequest = Auth_init_default;

    authRequest.type = 1;
    authRequest.version = 1;
    authRequest.apiKey.funcs.encode = encode_string_key;

    pb_ostream_t stream = pb_ostream_from_buffer(buffer, bufsize);

    status = encode_baseMessage(&stream, Auth_fields, &authRequest);

    if (!status) {
        printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));

    }

    return stream.bytes_written;

}


bool encode_temperatureMessage(pb_ostream_t *stream, const pb_field_t messagetype[], const void *message) {
    const pb_field_t *field;
    for (field = Temperature_fields; field->tag != 0; field++) {
        if (field->ptr == messagetype) {
            /* This is our field, encode the message using it. */
            if (!pb_encode_tag_for_field(stream, field)) {
                return false;
            } else {
                std::cout << "Write tag for Notify_fields " << stream->bytes_written << std::endl;
            }
            // return

            std::cout << "Write Notify_fields" << std::endl;

            return pb_encode_submessage(stream, messagetype, message);
        }
    }

    /* Didn't find the field for messagetype */
    return false;
}


bool encode_baseMessage1(pb_ostream_t *stream, const pb_field_t messagetype[], const void *message) {

    for (const pb_field_t *field = BaseMessage_fields; field->tag != 0; field++) {
        if (field->ptr == Temperature_fields) {

            if (!pb_encode_tag_for_field(stream, field)) {
                return false;
            } else {
                std::cout << "Write tag for Temperature_fields " << stream->bytes_written << std::endl;
            }
            // return

            std::cout << "Write Temperature_fields" << std::endl;

            //  This is our field, encode the message using it.


            return encode_temperatureMessage(stream, messagetype, message);
        }
    }

    /* Didn't find the field for messagetype */
    return false;
}


size_t notify(uint8_t *buffer, size_t bufsize) {

    Notify notify = Notify_init_default;
    // notify.current = 1;
    notify.heatingState = 0;
    notify.has_heatingState = true;

    pb_ostream_t stream = pb_ostream_from_buffer(buffer, bufsize);
    bool status = encode_baseMessage1(&stream, Notify_fields, &notify);
    if (!status) {
        printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));

    }
    return stream.bytes_written;
}


size_t notify2(uint8_t *buffer, size_t bufsize) {

    Notify notify = Notify_init_default;
    // notify.current = 1;
    notify.heatingState = 1;
    notify.has_heatingState = true;


    Temperature temperature = Temperature_init_default;

    temperature.notify = notify;
    temperature.has_notify = true;

    BaseMessage baseMessage = BaseMessage_init_default;

    baseMessage.temperature = temperature;
    baseMessage.has_temperature = true;


    pb_ostream_t stream = pb_ostream_from_buffer(buffer, bufsize);
  //  bool status = pb_encode(&stream, BaseMessage_fields, &baseMessage);

    bool status = pb_encode_varint(&stream, 300);
    if (!status) {
        printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));

    }
    return stream.bytes_written;
}


int main() {
    std::cout << "Start" << std::endl;

/*    {
        uint8_t bufferAuth[150];
        size_t sizeAuth = auth(bufferAuth, sizeof(bufferAuth));
        printBytes(bufferAuth, sizeAuth);
    }*/

/*    {
        uint8_t bufferNotify[128];
        size_t sizeNotify = notify(bufferNotify, sizeof(bufferNotify));
        printBytes(bufferNotify, sizeNotify);

    }*/

    {
        uint8_t bufferNotify[128];
        size_t sizeNotify = notify2(bufferNotify, sizeof(bufferNotify));
        printBytes(bufferNotify, sizeNotify);

    }


    return 0;
}

