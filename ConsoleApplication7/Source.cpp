//PM> Install-Package boost
//PM>Install-Package boost_serialization-vc110

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <string>
#include <fstream>
using namespace std;

struct Panda {
	int w;
	string name;

	template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & w;
		ar & name;
    }
};

int main() {
	Panda p;
	p.w = 666;
	p.name = "Ole";

	//ofstream out("out.txt"); 
	//boost::archive::text_oarchive out_archive(out);

	//out_archive << p;

	ifstream in("out.txt"); 
	boost::archive::text_iarchive in_archive(in);

	in_archive >> p;

	cout << p.w << " " << p.name;
	cin.get();
	return 0;
}