// dynamic_cast and an algorithm problem

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

        // dynamic programming style
        // make a table of max lengths for substrings,
        // with [1][1] being a comparison of the first letter of string1 and string2
        // [1][2] compares the first letter of string 1 and second letter of string 2
        // [2][1] compares the second letter of string 1 and first letter of string 2
        // and so on

        // acbc X abcdasdf
        // X 0 a b c d a s d f
        // 0 0 0 0 0 0 0 0 0 0
        // a 0 1 1 1 1 1 1 1 1
        // c 0 1 1 2 2 2 2 2 2
        // b 0 1 2 2 2 2 2 2 2
        // c 0 1 2 3 3 3 3 3 3

        vector<vector<int>> answers(short1v.size() + 1, vector<int>(short2v.size() + 1));

        // //DEBUG print
        // cout << "X 0";
        // for(int i = 0; i < short2v.size(); i++)
        //     cout << ' ' << short2v[i];
        // cout << endl;
        // cout << "0 0";
        // for(int i = 0; i < short2v.size(); i++)
        //     cout << " 0";
        // cout << endl;

        for (int i = 1; i < answers.size(); i++)
        {
            // //DEBUG print
            // cout << short1v[i-1] << " 0";

            for (int j = 1; j < answers[i].size(); j++)
            {
                // if these letters match, the score is 1 more than the score of previous of both
                // else no match; score is better of one less letter from either string
                if (short1v[i - 1] == short2v[j - 1])
                    answers[i][j] = answers[i - 1][j - 1] + 1;
                else
                    answers[i][j] = max(answers[i - 1][j], answers[i][j - 1]);

                // //DEBUG print
                // cout << ' ' << answers[i][j];
            }
            // //DEBUG print
            // cout << endl;
        }
        cout << answers.back().back() << endl;
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