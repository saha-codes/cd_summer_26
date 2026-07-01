#include <iostream>
using namespace std;

void tokenize(string input)
{
    string operators[]    = {"+","-","*","/","=","<<",">>","<",">"};
    string punctuations[] = {";",",","(",")","{","}"};
    string keywords[]     = {"int","float","char","if","else","for","while","cout","cin","return"};

    int start = 0, end = 0;

    while (end <= input.length())
    {
        if (end == input.length() || input[end] == ' ')
        {
            string token = "";
            for (int i = start; i < end; i++)
                token = token + input[i];

            if (token.length() == 0)
            {
                start = end + 1;
                end++;
                continue;
            }

            bool found = false;


            for (int i = 0; i < sizeof(operators)/sizeof(operators[0]); i++)
            {
                if (token == operators[i])
                {
                    cout << token << " = Operator"<<endl;
                    found = true;
                }
            }

            for (int i = 0; i < sizeof(punctuations)/sizeof(punctuations[0]); i++)
            {
                if (token == punctuations[i])
                {
                    cout << token << " = Punctuation"<<endl;
                    found = true;
                }
            }

            for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++)
            {
                if (token == keywords[i])
                {
                    cout << token << " = Keyword"<<endl;
                    found = true;
                }
            }


            if (!found)
            {
                if (token[0] >= '0' && token[0] <= '9')
                {
                    cout << token << " = Constant"<<endl;
                    found = true;
                }
            }


            if (!found)
            {
                if ((token[0] >= 'A' && token[0] <= 'Z') ||(token[0] >= 'a' && token[0] <= 'z') || token[0] == '_')
                {
                    bool valid = true;
                    for (int i = 1; i < (int)token.length(); i++)
                    {
                        if (!((token[i] >= 'A' && token[i] <= 'Z') || (token[i] >= 'a' && token[i] <= 'z') ||(token[i] >= '0' && token[i] <= '9') || token[i] == '_'))
                        {
                            valid = false;
                            break;
                        }
                    }

                    if (valid)
                    {
                        cout << token << " = Identifier"<<endl;
                        found = true;
                    }
                }
            }

            if (!found)
            {
                cout << token << " = Lexical Error"<<endl;
            }

            start = end + 1;
        }

        end++;
    }
}

int main()
{
    string input = "cout << 20 + a * 60.5";
    tokenize(input);
    return 0;
}
