FROM 0xfeedc0de64/qt-build

ADD . /tmp/QtZeiterfassung

RUN mkdir -p /tmp/build_QtZeiterfassung \
 && qmake /tmp/QtZeiterfassung -o /tmp/build_QtZeiterfassung/Makefile -config release \
 && make -C /tmp/build_QtZeiterfassung -j8 \
 && make -C /tmp/build_QtZeiterfassung install



FROM 0xfeedc0de64/qt-runtime

COPY --from=0 /tmp/build_QtZeiterfassung/bin /root/bin

COPY --from=0 /tmp/build_QtZeiterfassung/lib /root/lib

CMD /root/bin/zeiterfassung
