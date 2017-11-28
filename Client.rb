require "socket"
client =TCPSocket.open("192.168.0.121",2000)

puts "enter your message: "
message=gets.chomp

rhost=client.peeraddr.last
puts "#{rhost}"
client.write(message)
client.close 
