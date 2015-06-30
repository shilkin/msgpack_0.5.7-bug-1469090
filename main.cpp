#include <msgpack.hpp>
#include <iostream>
#include <cstring>

int main(int, char**)
{
    // pack
    msgpack::sbuffer buffer;
    msgpack::pack(buffer, 42);
    
    // unpack: assume that we receive some chunk of data [char *data, size_t size]
    msgpack::unpacker unpacker;
    unpacker.reserve_buffer(buffer.size()); 
    std::memcpy(unpacker.buffer(), buffer.data(), buffer.size()); // read into unpacker emulation
    unpacker.buffer_consumed(buffer.size());
    
    msgpack::unpacked unpacked;
    while (unpacker.next(&unpacked))
    {
        std::cout << unpacked.get() << std::endl;
    }
    
    return 0;
}