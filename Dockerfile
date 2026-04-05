FROM ubuntu:26.04


RUN apt update && apt upgrade && apt install fastfetch -y && fastfetch


