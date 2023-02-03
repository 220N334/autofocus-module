FROM chtakyol/autofocus-module

RUN apt-get install -y uuid-dev

RUN git clone https://github.com/premake/premake-core.git
WORKDIR premake-core
RUN make -f Bootstrap.mak linux
ENV PATH="$PATH:/premake-core/bin/release"
WORKDIR /

WORKDIR autofocus-module
COPY . .
# RUN premake5 gmake
# RUN make

CMD ["bash", "dockerstart.sh"]
# CMD ["bash"]