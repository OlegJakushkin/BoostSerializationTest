//PM> Install-Package boost
//PM>Install-Package boost_serialization-vc110

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <string>
#include <vector>
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
	//Panda p, q;
	//p.w = 666;
	//p.name = "Ole";

	//q.w = 333;
	//q.name = "Bla";

	vector<Panda> pan;
	//pan.push_back(p);
	//pan.push_back(q);

	//ofstream out("out.txt"); 
	//boost::archive::text_oarchive out_archive(out);

	//out_archive << pan;

	ifstream in("out.txt"); 
	boost::archive::text_iarchive in_archive(in);

	in_archive >> pan;
	for(auto & e : pan) {
		cout << e.w << " " <<  e.name << endl;
	}
	cin.get();
	return 0;
}