/* -----------------------------------------------------------------------------
 * Rule_extension_att_value.cpp
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

#include "Rule_extension_att_value.hpp"
#include "Visitor.hpp"
#include "ParserContext.hpp"

#include "Rule_token.hpp"

using namespace abnf;

Rule_extension_att_value::Rule_extension_att_value(
  const string& spelling, 
  const vector<const Rule*>& rules) : Rule(spelling, rules)
{
}

Rule_extension_att_value::Rule_extension_att_value(const Rule_extension_att_value& rule) : Rule(rule)
{
}

Rule_extension_att_value& Rule_extension_att_value::operator=(const Rule_extension_att_value& rule)
{
  Rule::operator=(rule);
  return *this;
}

const Rule_extension_att_value* Rule_extension_att_value::clone() const
{
  return new Rule_extension_att_value(this->spelling, this->rules);
}

void* Rule_extension_att_value::accept(Visitor& visitor) const
{
  return visitor.visit(this);
}

const Rule_extension_att_value* Rule_extension_att_value::parse(ParserContext& context)
{
  context.push("extension-att-value");

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
          rule = Rule_token::parse(context);
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
    rule = new Rule_extension_att_value(context.text.substr(s0, context.index - s0), e0);
  else
    context.index = s0;

  context.pop("extension-att-value", parsed);

  return (Rule_extension_att_value*)rule;
}

/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
