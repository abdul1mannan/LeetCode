// Last updated: 10/1/2025, 12:48:14 AM
class MyCalendar {

public:

    MyCalendar() {}

    bool book(int start, int end) {

        for (const auto& booking : bookings) {

            int s = booking.first;

            int e = booking.second;

            if (!(end <= s || start >= e)) {

                return false;

            }

        }

        bookings.push_back({start, end});

        return true;

    }

private:

    vector<pair<int, int>> bookings;

};