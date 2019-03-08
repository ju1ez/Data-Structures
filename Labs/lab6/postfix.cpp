
#include<bits/stdc++.h>
using namespace std;
//function that returns precedence of operators
int prec(char c)
{
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}
//function that takes an inflix expression -> postfix expression
void infixToPostfix(string s)
{
  std::stack <char> st;
  st.push('N');
  int l = s.length();
  string ns;
  for (int i = 0; i < l; i++)
  {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
      ns += s[i];
    else if (s[i] == '(')
      st.push('(');
    else if (s[i] == ')')
    {
      while (st.top() != 'N' && st.top() != '(')
      {
        char c = st.top();
        st.pop();
        ns += c;
      }
      if (st.top() == '(')
      {
        char c = st.top();
        st.pop();
      }
    } else {
      while (st.top() != 'N' && prec(s[i]) <= prec(st.top()))
      {
        char c = st.top();
        st.pop();
        ns += c;
      }
      st.push(s[i]);
    }
  }
  while (st.top() != 'N')
  {
    char c = st.top();
    st.pop();
    ns += c;
  }
  cout << ns << endl;
}
//driver
int main()
{
  string exp;
  cout << "Enter an Inflix Expression:" << endl;
  cin >> exp;
  cout << endl << "Your PostFix expression is:" << endl;
  infixToPostfix(exp);
  return 0;
}
