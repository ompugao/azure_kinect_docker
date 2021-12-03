FROM nvidia/cuda:11.0.3-cudnn8-devel-ubuntu18.04

RUN apt -y update && apt -y install curl software-properties-common \
	&& rm -rf /var/lib/apt/lists/*
RUN curl -sSL https://packages.microsoft.com/keys/microsoft.asc | apt-key add -
RUN apt-add-repository https://packages.microsoft.com/ubuntu/18.04/prod \
	&& apt -y update \
	&& ACCEPT_EULA=Y apt install -y k4a-tools libk4a1.4-dev\
	&& rm -rf /var/lib/apt/lists/*

RUN apt -y update && apt -y install cmake \
	&& rm -rf /var/lib/apt/lists/*
ENV NVIDIA_VISIBLE_DEVICES \
    ${NVIDIA_VISIBLE_DEVICES:-all}
ENV NVIDIA_DRIVER_CAPABILITIES \
	${NVIDIA_DRIVER_CAPABILITIES:+$NVIDIA_DRIVER_CAPABILITIES,}graphics

