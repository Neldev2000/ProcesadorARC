cd ~
sudo apt-get update
sudo apt-get install build-essential


wget https://accellera.org/images/downloads/standards/systemc/systemc-2.3.3.tar.gz
tar -xvf systemc-2.3.3.tar.gz

cd systemc-2.3.3
mkdir objdir
cd objdir

SYSTEMC_HOME=/usr/local/systemc-2.3.3

sudo ../configure --prefix=$SYSTEMC_HOME/
make

sudo mkdir $SYSTEMC_HOME

sudo make install && echo "SystemC has been installed successfully"


cat << EOF > hello_world.cpp
#include <systemc.h>
class ModuleHelloWorld : public sc_module {
  public:
    SC_CTOR (ModuleHelloWorld) {
      SC_METHOD(sayHello);
    }
  private:
    void sayHello() {
      cout << "Hello World SystemC-2.3.3" << endl;
    }
};
int sc_main(int argc, char* argv[]) {
  ModuleHelloWorld hello("HELLO");
  sc_start();
  return 0;
}
EOF

if [ `getconf LONG_BIT` = "64" ]
then
  echo "64 bits system was detected"
  SYSTEMC_LIB=lib-linux64
else
  echo "32 bits system was[sudo] password for nvivas:
d"
  SYSTEMC_LIB=lib-linux
fi


g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/$SYSTEMC_LIB -Wl,-rpath=$SYSTEMC_HOME/$SYSTEMC_LIB -o hello_world hello_world.cpp -lsystemc -lm


./hello_world && echo "SystemC is running successfully"Sorry, try again.
