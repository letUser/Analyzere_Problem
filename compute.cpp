#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

float MIN_VALUE = 0.0;
float MAX_VALUE = 1000000000.0;
int MAX_INPUT_SIZE = 100;

float compute(float number, float result, float threshold, float limit) {
	float computeNumber = max(MIN_VALUE, number - threshold);

	if ((computeNumber + result) > limit) {
		computeNumber = max(MIN_VALUE, limit - result);
	}

	return computeNumber;
}

int main(int argc, char **argv) {
	float threshold = atof(argv[1]);
	float limit = atof(argv[2]);
	float result = 0.0;
	vector<float> numbers;

	// avoid scientific notation for output stream
	cout.setf(ios::fixed);

	// collect the inputs
	for (int i = 0; i < MAX_INPUT_SIZE; ++i) {
		string line;
		float currentNumber;

		getline(cin, line);

		// handle empty line and EOF
		if (line.empty() || cin.eof()) break;

		// try to parse float number from string
		try {
			currentNumber = stof(line);

			numbers.push_back(currentNumber);
		}
		catch(invalid_argument) {
			break;
		}
		catch (out_of_range) {
			break;
		}
	}

	// outputs loop (can not make it in first loop, need to gather ALL inputs firstly)
	for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {

		float computeNumber = compute(*iter, result, threshold, limit);

		cout << setprecision(1) << computeNumber << endl;

		result = result + computeNumber;
	}

	cout << setprecision(1) << result << endl;
};
