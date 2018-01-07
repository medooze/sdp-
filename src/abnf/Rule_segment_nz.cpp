/* -----------------------------------------------------------------------------
 * Rule_segment_nz.cpp
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

#include "Rule_segment_nz.hpp"
#include "Visitor.hpp"
#include "ParserContext.hpp"

#include "Rule_pchar.hpp"

using namespace abnf;

Rule_segment_nz::Rule_segment_nz(
  const string& spelling, 
  const vector<const Rule*>& rules) : Rule(spelling, rules)
{
}

Rule_segment_nz::Rule_segment_nz(const Rule_segment_nz& rule) : Rule(rule)
{
}

Rule_segment_nz& Rule_segment_nz::operator=(const Rule_segment_nz& rule)
{
  Rule::operator=(rule);
  return *this;
}

const Rule_segment_nz* Rule_segment_nz::clone() const
{
  return new Rule_segment_nz(this->spelling, this->rules);
}

void* Rule_segment_nz::accept(Visitor& visitor) const
{
  return visitor.visit(this);
}

const Rule_segment_nz* Rule_segment_nz::parse(ParserContext& context)
{
  context.push("segment-nz");

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
          rule = Rule_pchar::parse(context);
          if ((f1 = rule != NULL))
          {
            e1.push_back(rule);
            c1++;
          }
        }
        for (int i1 = 0; f1; i1++)
        {
          rule = Rule_pchar::parse(context);
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
    rule = new Rule_segment_nz(context.text.substr(s0, context.index - s0), e0);
  else
    context.index = s0;

  context.pop("segment-nz", parsed);

  return (Rule_segment_nz*)rule;
}

/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
