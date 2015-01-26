
#include <random>
#include <iostream>
#include <cmath>
#include <sstream>

int main(int argc, char **argv) {
	// ‹[——”¶¬Ší
	std::random_device rnd;
	auto seed = rnd();
	std::mt19937 mt(seed);
	std::uniform_real_distribution<> dist(0.0, 1.0);

	std::cout << "seed," << seed << std::endl;

	// ŸŒ³
	int n = 2;
	if (argc > 1) {
		std::stringstream ss;
		ss << argv[1];
		ss >> n;
	}

	std::cout << "dimension," << n << std::endl;

	std::cout << std::endl;

	auto gamma = std::tgamma(n / 2.0 + 1);
	auto pow2 = std::pow(2.0, n);
	for (int points = 1000; points <= 100000; points += 1000) {
		// points ‰ñƒ‰ƒ“ƒ_ƒ€‚É“_‚ğ‘Å‚¿A‹…‚Ì“à‘¤‚É“ü‚Á‚½”‚ğ”‚¦‚é
		int hit = 0;
		for (int i = 0; i < points; ++i) {
			double d = 0.0;
			for (int i = 0; i < n; ++i) {
				auto v = dist(mt);
				d += v * v;
			}
			if (d <= 1) {
				++hit;
			}
		}

		// ‰~ü—¦‚ğ‹‚ß‚é
		auto res = std::pow(hit * pow2 * gamma / points, 2.0 / n);
		std::cout << points << "," << res << std::endl;
	}

	return 0;
}
