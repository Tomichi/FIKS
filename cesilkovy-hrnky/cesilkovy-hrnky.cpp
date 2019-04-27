#include <iostream>

using namespace std;

int main(void)
{
	int n, first, load, previous, breaks = 0;
	bool corect = true;
	cin >> n;
	if (n != 0) {
		cin >> first;
		previous = first;
	}

	for (int i = 1; i < n; i++) {
		cin >> load;
		if (load < previous) {
			corect = false;
			++breaks;
			if (breaks > 1) break;
		}
		previous = load;
	}
	
	if (corect || (breaks == 1 && first >= load)) {
		cout << "Lze preskladat\n";
	} else {
		cout << "Nelze preskladat\n";
	}

	return 0;
}
