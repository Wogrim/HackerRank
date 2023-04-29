// dynamic_cast and an algorithm problem -- too slow

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell
{
private:
    string scrollName;

public:
    Spell() : scrollName("") {}
    Spell(string name) : scrollName(name) {}
    virtual ~Spell() {}
    string revealScrollName()
    {
        return scrollName;
    }
};

class Fireball : public Spell
{
private:
    int power;

public:
    Fireball(int power) : power(power) {}
    void revealFirepower()
    {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell
{
private:
    int power;

public:
    Frostbite(int power) : power(power) {}
    void revealFrostpower()
    {
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell
{
private:
    int power;

public:
    Thunderstorm(int power) : power(power) {}
    void revealThunderpower()
    {
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell
{
private:
    int power;

public:
    Waterbolt(int power) : power(power) {}
    void revealWaterpower()
    {
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal
{
public:
    static string journal;
    static string read()
    {
        return journal;
    }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell)
{
    //////////////////////////////////////////////////////////////
    // MY CODE START

    // dynamic_cast<>() to see which child class the spell is
    if (dynamic_cast<Fireball *>(spell) != nullptr)
        dynamic_cast<Fireball *>(spell)->revealFirepower();
    else if (dynamic_cast<Frostbite *>(spell) != nullptr)
        dynamic_cast<Frostbite *>(spell)->revealFrostpower();
    else if (dynamic_cast<Thunderstorm *>(spell) != nullptr)
        dynamic_cast<Thunderstorm *>(spell)->revealThunderpower();
    else if (dynamic_cast<Waterbolt *>(spell) != nullptr)
        dynamic_cast<Waterbolt *>(spell)->revealWaterpower();
    else
    {
        string s1 = spell->revealScrollName();
        string s2 = SpellJournal::read();

        // reduce the strings to letters that are in both,
        // would be easier if we could use other includes
        vector<bool> in1(256, false);
        vector<bool> in2(256, false);
        for (int i = 0; i < s1.length(); i++)
            in1[s1[i]] = true;
        for (int i = 0; i < s2.length(); i++)
            in2[s2[i]] = true;
        vector<bool> inboth(256, false);
        for (int i = 0; i < 256; i++)
        {
            if (in1[i] && in2[i])
                inboth[i] = true;
        }
        vector<char> short1v, short2v;
        for (int i = 0; i < s1.length(); i++)
        {
            if (inboth[s1[i]])
                short1v.push_back(s1[i]);
        }
        for (int i = 0; i < s2.length(); i++)
        {
            if (inboth[s2[i]])
                short2v.push_back(s2[i]);
        }

        //make it so short2v is the shorter one
        //because we will try to fit as much as possible into short1v
        if(short1v.size() < short2v.size())
            short1v.swap(short2v);

        /*
        //DEBUG print the words with only common letters
        for(int i = 0; i < short1v.size(); i++)
            cout << short1v[i];
        cout << endl;
        for(int i = 0; i < short2v.size(); i++)
            cout << short2v[i];
        cout << endl;
        */

        //if the shorter word is less than 2 letters, we are done
        if(short2v.size()<2)
        {
            cout << short2v.size() << endl;
            return;
        }
        //else
        
        //length of the longest word we've found
        int longest = 1;

        //vectors for all possible combinations of the letters in short2v
        //array index is word size, outer vector is list of words,
        //inner vector of ints is short2v letter indices for the word
        vector<vector<int>> wordlists[short2v.size()+1];

        //create all one letter words
        for(int i = 0; i < short2v.size(); i++)
        {
            wordlists[1].emplace_back(1,i);
        }

        //loop through all possible word lengths
        for(int h = 2; h <= short2v.size(); h++)
        {
            //cout << "trying " << h << " letter words" << endl; //DEBUG
            //for each h-1 letter word that has success
            vector<vector<int>>::iterator words_i;
            for(words_i = wordlists[h-1].begin(); words_i != wordlists[h-1].end(); words_i++)
            {
                //create all possible h letter words
                for(int j = (*words_i).back()+1; j < short2v.size(); j++)
                {
                    wordlists[h].emplace_back(*words_i);
                    wordlists[h].back().push_back(j);
                }
            }
            //from a letters perspective there may be duplicates
            //because we created these by index of letters
            //convert to letters and remove duplicates?

            //try all possible h letter words, and save the ones that work (vector erase slow)
            vector<vector<int>> success;
            for(words_i = wordlists[h].begin(); words_i != wordlists[h].end(); words_i++)
            {
                //where in short1v we are comparing the current character of the word to
                int i1 = 0;
                //loop through characters in the h-letter word
                for(int i2 = 0; i2 < (*words_i).size(); i2++)
                {
                    //look through short1v for the current character
                    while(i1 < short1v.size() && short1v[i1] != short2v[(*words_i)[i2]])
                        i1++;

                    //if we have matching letters
                    if(short1v[i1] == short2v[(*words_i)[i2]])
                    {
                        //if it is last letter of the word, good word
                        if(i2 == (*words_i).size()-1)
                        {
                            success.emplace_back(*words_i);
                            break;
                        }
                        else //we must point i1 to the next letter in short1v
                            i1++;
                    }
                    else //we reached the end of short1v without matching current letter (bad word)
                        break;
                }
            }

            //if we have no success we are done
            if(success.empty())
                break;
            //else
            longest = h;
            wordlists[h].clear();
            wordlists[h] = success;


            // //DEBUG
            // cout << "success with " << success.size() << " " << h << " letter words" << endl;
            // for(int i = 0; i < success.size(); i++)
            // {
            //     for(int j = 0; j < success[i].size(); j++)
            //         cout << short2v[success[i][j]];
            //     cout << endl;
            // }

        }
        //the longest word was found in the loop, unless no 2-letter words worked
        cout << longest << endl;
        
    }
    delete spell;

    // MY CODE END
    //////////////////////////////////////////////////////////////
}

class Wizard
{
public:
    Spell *cast()
    {
        Spell *spell;
        string s;
        cin >> s;
        int power;
        cin >> power;
        if (s == "fire")
        {
            spell = new Fireball(power);
        }
        else if (s == "frost")
        {
            spell = new Frostbite(power);
        }
        else if (s == "water")
        {
            spell = new Waterbolt(power);
        }
        else if (s == "thunder")
        {
            spell = new Thunderstorm(power);
        }
        else
        {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main()
{
    int T;
    cin >> T;
    Wizard Arawn;
    while (T--)
    {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}