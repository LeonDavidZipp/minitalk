#!/bin/bash

#run this script in may terminals simultaneously to check if server handles correctly
# Replace with your server's PID
server_pid=12345

echo "Correct number of args."
# Test cases
declare -a strings=("Hello" "World" "Test" "1234567890" "!@#$%^&*()" "😀😃😄😁" "こんにちは" "你好" "🌍🌎🌏")

# Run the client with each test case
for str in "${strings[@]}"; do
    echo "Sending string '$str' to server with PID $server_pid"
    ./client $server_pid "$str"
    sleep 1  # Wait a bit between tests
done

echo "Incorrect number of args."
./client $server_pid "Hello" "World"
./client $server_pid
./client $server_pid "Hello" "World" "Test"
./client $server_pid "Hello" "World" "Test" "1234567890"
,/client $server_pid Hello World Test 1234567890 "!@#$%^&*()"

echo "wrong pids"
./client $(($server_pid+1)) "Hello"
./client $(($server_pid-1)) "World"
./client 1 "Test"
