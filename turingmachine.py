import sys

class TuringMachine:

    def __init__ (self, src):
        self._tape = dict(enumerate(src.readline().strip()))
        self._head = min(src.readline().index('^'), len(self._tape) - 1)
        self._state = src.readline().strip()
        self._rules = {}
        for rule in src:
            rule = self.parse_rule(rule)
            if rule is not None:
                self._rules[rule[0]] = rule[1]

    def parse_rule (self, rule):
        rule = rule.split(';', 1)[0].strip()
        if rule == '': return None
        try:
            pattern, result = rule.split(':')
            p_st, p_sym = [p.strip() for p in pattern.strip().split(' ')]
            r_st, r_sym, r_dir = [r.strip() for r in result.strip().split(' ')]
            if r_dir not in ['<', '>'] or len(p_sym) != 1 or len(r_sym) != 1:
                raise
            return (p_st, p_sym), (r_st, r_sym, r_dir)
        except:
            print('Malformed rule: "%s"' % rule)
            sys.exit()

    def print_tape (self):
        pos = 0
        count = 0
        for i in sorted(self._tape):
            print(self._tape[i], end='')
            if self._head == i:
                pos = count
            count += 1
        print('')
        print(' ' * pos, end='^ (%s)\n' % self._state)

    def step (self):
        status = (self._state, self._tape[self._head])
        if status in self._rules :
            ns,s,d = self._rules[status] #nouvel etat, symbole, direction
            self._state = ns
            self._tape[self._head] = s
            if d == '>' :
                self._head += 1
            else : 
                self._head -= 1
            if self._head not in self._tape :
                self._tape[self._head] = '_'
            return True
        else :
            print('arret')
            return False

if __name__ == '__main__':
    src = open(sys.argv[1], 'r')
    tm = TuringMachine(src)
    step = 0
    print('> Initial state:')
    tm.print_tape()
    input('\nEnter to continue…')
    while tm.step():
        step += 1
        print('\n> Step %d:' % step)
        tm.print_tape()
        input('\nEnter to continue…')
    src.close()
