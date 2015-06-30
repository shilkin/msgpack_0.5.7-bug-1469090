# Application for reproducing msgpack_0.5.7 bug #1469090

Link: https://bugs.launchpad.net/ubuntu/+source/msgpack/+bug/1469090

## Usage
```bash
sudo apt-get install git
sudo apt-get install cmake
sudo apt-get install libmsgpack-dev
sudo apt-get install valgrind
git clone https://github.com/shilkin/msgpack_0.5.7-bug-1469090.git
cd msgpack_0.5.7-bug-1469090
cmake .
make
make check
tail ./valgrind.log
```

## Testing environment
```bash
docker run -ti --name=msgpack-bug-1469090 ubuntu:utopic bash
```

