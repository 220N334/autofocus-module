FROM scratch
ADD mynewimage.tar /
RUN docker load < /mynewimage.tar

RUN git clone https://github.com/220N334/raspicam.git
WORKDIR raspicam
RUN mkdir build
WORKDIR build
RUN cmake ..
RUN make
RUN make install
RUN ldconfig

WORKDIR /

WORKDIR autofocus-module
COPY . .
WORKDIR scripts
RUN bash GenerateProjectArm.sh
RUN bash RunProjectArm.sh
