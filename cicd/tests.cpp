#include <iostream>
#include <string>
using namespace std;

int run_test(string name, string input, string expect);

int main(int argc, char *argv[])
{
	int result;

	/*result += run_test(
		"Test for test",
		"lol",
		"lol"
	);*/

	result += run_test(
		"Test 1",
		"to be or not to be. thats the question.",
		"not. question. "
	);

	result += run_test(
		"Test 2",
		". .. f .see omg to lol.",
		"f. see omg lol. "
	);

	result += run_test(
		"Test 3",
		"",
		"wrong test text"
	);

	result += run_test(
		"Test 4",
		"lol",
		"not lol"
	);

	return 0;
}

int run_test(string name, string input, string expect)
{
	string command = "echo \"" + input + "\" | ../usr/bin/sentrim";
	//cout << "EXECUTING COMMAND: " << command << '\n';
	FILE* pipe = popen(command.c_str(), "r");
	if (!pipe) {
		throw runtime_error("popen failed");
	}

	char buffer[128];
	string result;
	while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
		result += buffer;
	}
	pclose(pipe);

	// remove '\n' from result
	result = result.substr(0, result.find('\n'));
	//cout << "got: " << result << '\n';
	//cout << "expected: " << expect << '\n';
	if (!result.compare(expect)) {
		cout << name << " passed\n";
		return 0;
	}

	cout << name << " failed\n";
	return 1;
}
