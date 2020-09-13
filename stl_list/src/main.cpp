#include "common.h"

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    
    cout << "Playing: " << endl;
    cout << song << endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    
    auto it = playlist.begin ();

    while (it != playlist.end ()) {

        cout << *it << endl;

        it++;
    }

    cout << "Current song: " << endl;
    cout << current_song << endl;
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();

    Char choice;
    bool quit = false;

    display_playlist (playlist, *current_song);
    
    while (!quit) {

        display_menu ();

        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        choice = std::toupper (choice);

        switch (choice) {

            case 'F':
                current_song = playlist.begin ();
                play_current_song (*current_song);
                break;

            case 'N':
                current_song++;

                if (current_song == playlist.end ())
                    current_song = playlist.begin ();

                play_current_song (*current_song);
                break;

            case 'P':

                if (current_song != playlist.begin ())
                    current_song--;
                else {

                    current_song = playlist.end ();
                    current_song--;
                }

                play_current_song (*current_song);
                break;

            case 'A': {
                String name;
                String artist;
                Int rating = 1;

                cout << "Adding and playing new song" << endl;
                cout << "Enter song name: ";
                getline (cin, name);
                cout << "Enter artist name: ";
                getline (cin, artist);
                cout << "Enter rating (1-5): ";
                cin >> rating;

                playlist.insert (current_song, Song {name, artist, rating});

                current_song--;
                play_current_song (*current_song);
                
                break;
            }
                
            case 'L':
                display_playlist (playlist, *current_song);
                break;

            case 'Q':
                quit = true;
                break;
        }        
    }

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}