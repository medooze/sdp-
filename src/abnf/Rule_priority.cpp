/* -----------------------------------------------------------------------------
 * Rule_priority.cpp
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

#include "Rule_priority.hpp"
#include "Visitor.hpp"
#include "ParserContext.hpp"

#include "Rule_DIGIT.hpp"

using namespace abnf;

Rule_priority::Rule_priority(
  const string& spelling, 
  const vector<const Rule*>& rules) : Rule(spelling, rules)
{
}

Rule_priority::Rule_priority(const Rule_priority& rule) : Rule(rule)
{
}

Rule_priority& Rule_priority::operator=(const Rule_priority& rule)
{
  Rule::operator=(rule);
  return *this;
}

const Rule_priority* Rule_priority::clone() const
{
  return new Rule_priority(this->spelling, this->rules);
}

void* Rule_priority::accept(Visitor& visitor) const
{
  return visitor.visit(this);
}

const Rule_priority* Rule_priority::parse(ParserContext& context)
{
  context.push("priority");

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
        for (int i1 = 0; i1 < 1 && f1; i1++)
        {
          rule = Rule_DIGIT::parse(context);
          if ((f1 = rule != NULL))
          {
            e1.push_back(rule);
            c1++;
          }
        }
        for (int i1 = 1; i1 < 10 && f1; i1++)
        {
          rule = Rule_DIGIT::parse(context);
          if ((f1 = rule != NULL))
          {
            e1.push_back(rule);
            c1++;
          }
        }
        parsed = c1 >= 1;
      }
      if (parsed)
        e0.insert(e0.end(), e1.begin(), e1.end());
      else
        context.index = s1;
    }
  }

  rule = NULL;
  if (parsed)
    rule = new Rule_priority(context.text.substr(s0, context.index - s0), e0);
  else
    context.index = s0;

  context.pop("priority", parsed);

  return (Rule_priority*)rule;
}

/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
