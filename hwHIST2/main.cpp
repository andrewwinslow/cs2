
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include "browserhistory.h"

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file << ", line " << line << "." << endl;
        abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


void interactive_mode()
{
	cout << "Choose (B)ack, (F)orward, or enter a url to go to." << endl;

	BrowserHistory bh("http://google.com");

	string line;
	while (cin)
	{
		string line;
		getline(cin, line);
		if (line == "B")
		{
			if (bh.can_go_back())
			{
				bh.back();
				cout << "    Back to " << bh.current_url() << endl;
			}
			else
				cout << "    Cannot go back." << endl;
				
		}
		else if (line == "F")
		{
			if (bh.can_go_forward())
			{
				bh.forward();
				cout << "    Forward to " << bh.current_url() << endl;
			}
			else
				cout << "    Cannot go forward." << endl;
		}
		else
		{
			bh.go_to_url(line);
			cout << "    Gone to " << bh.current_url() << endl;
		}
	}
	exit(0);
}


int main()
{
	// Uncomment line below to use your BrowserHistory interactively.
	// interactive_mode();


	// Comments below indicate the current (expected) state of the history.
	// Example: [url1, url2, url3, (url4), url5, url6]
	// The urls are listed oldest to newest from left to right, 
	// and the url in parentheses is the current url. 

	// History: [(google.com)]
	BrowserHistory bh("http://google.com");
	test(bh.current_url() == "http://google.com");
	test(!bh.can_go_back());
	test(!bh.can_go_forward());	
	test(bh.past_url_count() == 0);
	test(bh.future_url_count() == 0);

	bh.go_to_url("http://netflix.com");
	bh.go_to_url("http://amazon.com");
	bh.go_to_url("http://utrgv.edu");
	// History: [google.com, netflix.com, amazon.com, (utrgv.edu)]
	test(bh.current_url() == "http://utrgv.edu");
	test(bh.can_go_back());
	test(!bh.can_go_forward());	
	test(bh.past_url_count() == 3);
	test(bh.future_url_count() == 0);
	
	bh.back();
	bh.back();
	// History: [google.com, (netflix.com), amazon.com, utrgv.edu]
	test(bh.current_url() == "http://netflix.com");
	test(bh.can_go_back());
	test(bh.can_go_forward());
	test(bh.past_url_count() == 1);
	test(bh.future_url_count() == 2);

	bh.forward();
	// History: [google.com, netflix.com, (amazon.com), utrgv.edu]
	test(bh.current_url() == "http://amazon.com");
	test(bh.can_go_back());
	test(bh.can_go_forward());
	test(bh.past_url_count() == 2);
	test(bh.future_url_count() == 1);

	// History: [google.com, netflix.com, amazon.com, (youtube.com)]
	bh.go_to_url("http://youtube.com");
	test(bh.current_url() == "http://youtube.com");
	test(bh.can_go_back());
	test(!bh.can_go_forward());
	test(bh.past_url_count() == 3);
	test(bh.future_url_count() == 0);
	bh.forward(); // Can't go forward any more, so do nothing	
	test(bh.current_url() == "http://youtube.com");
	
	bh.back();
	bh.back();
	bh.back();
	// History: [(google.com), netflix.com, amazon.com, youtube.com]
	test(bh.current_url() == "http://google.com");
	bh.back(); // Can't go back any more, so do nothing
	test(bh.current_url() == "http://google.com");

	for (int i = 0; i < 100; ++i)
	{
		ostringstream oss;
		oss << "http://url" << i+1 << ".com";
		bh.go_to_url(oss.str());
	} 
	// History: [(google.com), url1.com, url2.com, ..., url99.com, url100.com]
	for (int i = 0; i < 50; ++i)
		bh.back();
	test(bh.current_url() == "http://url50.com");	

	cout << "Assignment complete." << endl;
}



