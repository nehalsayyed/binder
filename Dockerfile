FROM ubuntu:26.04
RUN apt update && apt upgrade -y && apt install fastfetch -y && fastfetch
