/* -----------------------------------------------------------------------------
 * Rule_base64_pad.cpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.2
 * Produced : Sun Jan 07 16:41:36 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Rule_base64_pad.hpp"
#include "Visitor.hpp"
#include "ParserContext.hpp"

#include "Rule_base64_char.hpp"
#include "Terminal_StringValue.hpp"

using namespace abnf;

Rule_base64_pad::Rule_base64_pad(
  const string& spelling, 
  const vector<const Rule*>& rules) : Rule(spelling, rules)
{
}

Rule_base64_pad::Rule_base64_pad(const Rule_base64_pad& rule) : Rule(rule)
{
}

Rule_base64_pad& Rule_base64_pad::operator=(const Rule_base64_pad& rule)
{
  Rule::operator=(rule);
  return *this;
}

const Rule_base64_pad* Rule_base64_pad::clone() const
{
  return new Rule_base64_pad(this->spelling, this->rules);
}

void* Rule_base64_pad::accept(Visitor& visitor) const
{
  return visitor.visit(this);
}

const Rule_base64_pad* Rule_base64_pad::parse(ParserContext& context)
{
  context.push("base64-pad");

  bool parsed = true;
  int s0 = context.index;
  vector<const Rule*> e0;
  const Rule* rule;

  parsed = false;
  if (!parsed)
  {
    {
      vector<const Rule*> e1;
      int s1 = context.index;
      parsed = true;
      if (parsed)
      {
        bool f1 = true;
        int c1 = 0;
        for (int i1 = 0; i1 < 2 && f1; i1++)
        {
          rule = Rule_base64_char::parse(context);
          if ((f1 = rule != NULL))
          {
            e1.push_back(rule);
            c1++;
          }
        }
        parsed = c1 == 2;
      }
      if (parsed)
      {
        bool f1 = true;
        int c1 = 0;
        for (int i1 = 0; i1 < 1 && f1; i1++)
        {
          rule = Terminal_StringValue::parse(context, "==");
          if ((f1 = rule != NULL))
          {
            e1.push_back(rule);
            c1++;
          }
        }
        parsed = c1 == 1;
      }
      if (parsed)
        e0.insert(e0.end(), e1.begin(), e1.end());
      else
        context.index = s1;
    }
  }
  if (!parsed)
  {
    {
      vector<const Rule*> e1;
      int s1 = context.index;
      parsed = true;
      if (parsed)
      {
        bool f1 = true;
        int c1 = 0;
        for (int i1 = 0; i1 < 3 && f1; i1++)
        {
          rule = Rule_base64_char::parse(context);
          if ((f1 = rule != NULL))
          {
            e1.push_back(rule);
            c1++;
          }
        }
        parsed = c1 == 3;
      }
      if (parsed)
      {
        bool f1 = true;
        int c1 = 0;
        for (int i1 = 0; i1 < 1 && f1; i1++)
        {
          rule = Terminal_StringValue::parse(context, "=");
          if ((f1 = rule != NULL))
          {
            e1.push_back(rule);
            c1++;
          }
        }
        parsed = c1 == 1;
      }
      if (parsed)
        e0.insert(e0.end(), e1.begin(), e1.end());
      else
        context.index = s1;
    }
  }

  rule = NULL;
  if (parsed)
    rule = new Rule_base64_pad(context.text.substr(s0, context.index - s0), e0);
  else
    context.index = s0;

  context.pop("base64-pad", parsed);

  return (Rule_base64_pad*)rule;
}

/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
