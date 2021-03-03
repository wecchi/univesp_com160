 /* Videoaula 4 -  12:05 
    Criando uma classe para a estrutura de tempo (horas, minutos e segundos)
 */
#ifndef TIME_H
#define TIME_H
    class Time {
        private: // seção privada
            // Membros privados
            int hour;    // 0 - 23
            int minute;  // 0 - 59
            int second;  // 0 - 59

        public: // seção pública
            Time(int hour = 0, int minute = 0, int second = 0);
            int getHour() const;
            void setHour(int hour);
            int getMinute() const;
            void setMinute(int minute);
            int getSecond() const;
            void setSecond(int second);
            void print() const;
            void nextSecond();

    };
#endif