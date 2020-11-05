
class Team {
public:
	std::string name;
	int victory;
	Team(const std::string& n = "X", int v = 0) : name(n), victory(v) {}
	Team& operator+=(const Team& rhs) {
		victory += rhs.victory;
		return *this;
	}
	friend Team operator+(Team a, const Team& b) {
		a += b;
		return a;
	}
	friend bool operator==(const Team& a, const Team& b) {
		return (a.name == b.name);
	}
	friend bool operator!=(const Team& a, const Team& b) {
		return !(a == b);
	}
	friend std::ostream& operator << (std::ostream& os, const Team& n) {
		os << n.name << "(" << n.victory << ")";
		return os;
	}
};