#!/bin/bash

#start the server, then run everything below in a new terminal
#run this script in may terminals simultaneously to check if server handles correctly
# Replace with your server's PID
server_pid=34794
make cm
echo "Correct number of args."
# Test cases
declare -a strings=("Hello" "World" "Test" "1234567890" "!@#$%^&*()" "😀😃😄😁" "こんにちは" "你好" "🌍🌎🌏" "dnsvjdviuvhu34fojdocjdsiousdiuhisucjkdscbchjbdsckndjkscndnsclcklmdklcmdsmcklmlscmdkcmdmckldklvndjksnvjkvdfnkvnvnjkdfnkvndfvvfjvnfnvjknfvnfjknvkfnvnknvkfnnvfjknvkdflv;kekepofkmvmdklvfjiofjiofjjfdmvklndfvkiofgjerrferfklrfklrklfjfjiojrferfklenrkfjnerfnej6t37t47t47t2347t4237t4367t467t34t347t2367t4t3467t346723vrf3tftyf43f43ty4fcffxgtyfxtyf4tyf3ty4f3tyf44tyf34f34f3t4f23ty4f23tyf4f34tyxg4vghvhgv4v23h4hv4ghv3hg24krfnejkrfnjker")

# Run the client with each test case
for str in "${strings[@]}"; do
    echo "Sending string '$str' to server with PID $server_pid"
    ./client $server_pid "$str"
    # sleep 1  # Wait a bit between tests
done

echo "Incorrect number of args."
./client $server_pid "Hello" "World"
./client $server_pid
./client $server_pid "Hello" "World" "Test"
./client $server_pid "Hello" "World" "Test" "1234567890"
,/client $server_pid Hello World Test 1234567890 "!@#$%^&*()"
