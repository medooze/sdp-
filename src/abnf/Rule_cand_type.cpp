/* -----------------------------------------------------------------------------
 * Rule_cand_type.cpp
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

#include "Rule_cand_type.hpp"
#include "Visitor.hpp"
#include "ParserContext.hpp"

#include "Rule_candidate_types.hpp"
#include "Rule_SP.hpp"
#include "Terminal_StringValue.hpp"

using namespace abnf;

Rule_cand_type::Rule_cand_type(
  const string& spelling, 
  const vector<const Rule*>& rules) : Rule(spelling, rules)
{
}

Rule_cand_type::Rule_cand_type(const Rule_cand_type& rule) : Rule(rule)
{
}

Rule_cand_type& Rule_cand_type::operator=(const Rule_cand_type& rule)
{
  Rule::operator=(rule);
  return *this;
}

const Rule_cand_type* Rule_cand_type::clone() const
{
  return new Rule_cand_type(this->spelling, this->rules);
}

void* Rule_cand_type::accept(Visitor& visitor) const
{
  return visitor.visit(this);
}

const Rule_cand_type* Rule_cand_type::parse(ParserContext& context)
{
  context.push("cand-type");

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
          rule = Terminal_StringValue::parse(context, "typ");
          if ((f1 = rule != NULL))
          {
            e1.push_back(rule);
            c1++;
          }
        }
        parsed = c1 == 1;
      }
      if (parsed)
      {
        bool f1 = true;
        int c1 = 0;
        for (int i1 = 0; i1 < 1 && f1; i1++)
        {
          rule = Rule_SP::parse(context);
          if ((f1 = rule != NULL))
          {
            e1.push_back(rule);
            c1++;
          }
        }
        parsed = c1 == 1;
      }
      if (parsed)
      {
        bool f1 = true;
        int c1 = 0;
        for (int i1 = 0; i1 < 1 && f1; i1++)
        {
          rule = Rule_candidate_types::parse(context);
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
    rule = new Rule_cand_type(context.text.substr(s0, context.index - s0), e0);
  else
    context.index = s0;

  context.pop("cand-type", parsed);

  return (Rule_cand_type*)rule;
}

/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
