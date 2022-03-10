#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

// VISITOR DESIGN PATTERN

/* Est-ce qu'il faut redef destructeur si c'est pour une interface ? */

class Bestiole;

class iComportement {
    public:
        virtual ~iComportement(){cout<<"Destruction comportement"<<endl;};
        virtual void bougeSelonComportement(Bestiole b) const = 0;
};

class ComportementGregaire : public iComportement {
    public:
        void bougeSelonComportement(Bestiole b) const override;
}

class ComportementPeureuse : public iComportement {
    public:
        void bougeSelonComportement(Bestiole b) const override;
}

class ComportementKamikaze : public iComportement {
    public:
        void bougeSelonComportement(Bestiole b) const override;
}

class ComportementPrevoyante : public iComportement {
    public:
        void bougeSelonComportement(Bestiole b) const override;
}

class ComportementPersMultiple : public iComportement {
    public:
        void bougeSelonComportement(Bestiole b) const override;
}

#endif