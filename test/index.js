'use strict';
const Code = require('code');
const Lab = require('lab');
const { now, nowDouble, nowStruct } = require('../lib');

// Test shortcuts
const lab = exports.lab = Lab.script();
const { describe, it } = lab;
const { expect } = Code;


describe('Microtime', () => {
  it('validates results from all functions', () => {
    const n = now();
    const nd = nowDouble();
    const ns = nowStruct();

    expect(n).to.be.a.number();
    expect(nd).to.be.a.number();
    expect(ns).to.be.an.array();
    expect(ns.length).to.equal(2);
    expect(ns[0]).to.be.a.number();
    expect(ns[1]).to.be.a.number();

    // Verify millisecond resolution.
    expect((n + '').substr(-3)).to.equal('000');
    expect((ns[1] + '').substr(-3)).to.equal('000');
  });
});
