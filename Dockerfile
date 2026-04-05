FROM ubuntu:26.04


RUN apt update -y && apt upgrade -y && apt install fastfetch -y && fastfetch


